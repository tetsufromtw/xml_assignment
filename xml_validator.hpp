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
        std::string GetElement(const std::string& element);
        bool IsStartElement(const std::string& element);
        bool IsEndElement(const std::string& element);
        void HandleStartElement(const std::string& element);
        void HandleEndElement(const std::string& element);

};

