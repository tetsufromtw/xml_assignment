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

void XMLValidator::ParseXmlString(const std::string& xmlContent) {
    std::istringstream stream(xmlContent);
    std::string token;

    while (std::getline(stream, token, '>')) {
        size_t start = token.find('<');
        if (start != std::string::npos) {
            token = token.substr(start + 1);
        }
        if (token.empty()) continue;

        if (IsStartElement(token)) {
            HandleStartElement(token);
        } else if (IsEndElement(token)) {
            HandleEndElement(token);
        }
    }
}

void XMLValidator::HandleStartElement(const std::string& element) {
    std::string startElement = GetElement(element);
    elementStack.push(startElement);
}

void XMLValidator::HandleEndElement(const std::string& element) {
    std::string endElement = GetElement(element);

    if (!elementStack.empty() && elementStack.top() == endElement) {
        elementStack.pop();
    } else {
        throw std::runtime_error("End element does not match the start element.");
    }

}

std::string XMLValidator::GetElement(const std::string& element) {
    bool isEndTag = element.size() > 1 && element[0] == '/';
    size_t startPos = isEndTag ? 1 : 0;
    size_t endPos = element.find('>', startPos);
    return element.substr(startPos, endPos - startPos);
}

bool XMLValidator::IsStartElement(const std::string& element) {
    return !element.empty() && element[0] != '/';
}

bool XMLValidator::IsEndElement(const std::string& element) {
    return !element.empty() && element[0] == '/';
}

