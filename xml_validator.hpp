#include <stack>
#include <string>

class XMLValidator {
    public:
        XMLValidator() {

        }
        bool DeterminXml(const std::string& xmlContent);

    private:
        std::stack<std::string> elementStack;

        void ParseXmlString(const std::string& xmlContent);
        std::string GetElement(const std::string& token);
        bool IsStartTag(const std::string& token);
        bool IsEndTag(const std::string& token);
        bool IsSelfClosingTag(const std::string& token);
        void HandleStartElement(const std::string& startElement);
        void HandleEndElement(const std::string& endElement);

};

