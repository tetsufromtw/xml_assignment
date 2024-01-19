#include <sstream>
#include <iostream>
#include <stdexcept>
#include "xml_validator.hpp"


bool XMLValidator::DeterminXml(const std::string& xmlContent) {
    try {
        while (!elementStack.empty()) {
            elementStack.pop();
        }
        ParseXmlString(xmlContent);
        return elementStack.empty();
    } catch (const std::runtime_error& e) {
        return false;
    }
}


/* 
 * Parses the given XML string by splitting it into tags.
 * - Extracts tags from '<' to '>', throws an exception for empty tags.
 * - Ignores self-closing tags like `<br/>`.
 * - Calls `HandleStartElement` for start tags and `HandleEndElement` for end tags.
*/
void XMLValidator::ParseXmlString(const std::string& xmlContent) {
    std::istringstream stream(xmlContent);
    std::string token;

    while (std::getline(stream, token, '>')) {
        size_t start = token.find('<');
        if (start != std::string::npos) {
            token = token.substr(start + 1);
        }
        if (token.empty()) throw std::runtime_error("Empty element.");

        if (IsSelfClosingTag(token)) continue;

        if (IsStartTag(token)) {
            HandleStartElement(GetElement(token));
        } else if (IsEndTag(token)) {
            HandleEndElement(GetElement(token));
        }
    }
}


void XMLValidator::HandleStartElement(const std::string& startElement) {
    elementStack.push(startElement);
}


void XMLValidator::HandleEndElement(const std::string& endElement) {
    if (!elementStack.empty() && elementStack.top() == endElement) {
        elementStack.pop();
    } else {
        throw std::runtime_error("End element does not match the start element.");
    }

}


/*
 * Extracts and returns the element's name from a given XML tag.
 * Removes start/end tag markers from the tag string.
 * Examples:
 *  - "<Name>" becomes "Name"
 *  - "<Name page=1>" becomes "Name page=1"
 *  - "</Name>" becomes "Name"
*/
std::string XMLValidator::GetElement(const std::string& token) {
    bool isEndTag = token.size() > 1 && token[0] == '/';
    size_t startPos = isEndTag ? 1 : 0;
    size_t endPos = token.find('>', startPos);
    return token.substr(startPos, endPos - startPos);
}


bool XMLValidator::IsSelfClosingTag(const std::string& token) {
    return !token.empty() && token[token.length() - 1] == '/';
}


bool XMLValidator::IsStartTag(const std::string& token) {
    return !token.empty() && token[0] != '/';
}


bool XMLValidator::IsEndTag(const std::string& token) {
    return !token.empty() && token[0] == '/';
}

