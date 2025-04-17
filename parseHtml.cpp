#include <iostream>
#include <vector>
#include <gumbo.h>

std::string extractText(GumboNode* node) {
    if (node->type == GUMBO_NODE_TEXT) {
        return std::string(node->v.text.text);
    }
    if (node->type == GUMBO_NODE_ELEMENT) {
        std::string text;
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            GumboNode* child = static_cast<GumboNode*>(children->data[i]);
            text += extractText(child);
        }
        return text;
    }
    return "";
}

std::vector<std::vector<std::string>> parseTags(GumboNode* node) {
    std::vector<std::vector<std::string>> result;

    if (node->type == GUMBO_NODE_ELEMENT) {
        std::string tagName = gumbo_normalized_tagname(node->v.element.tag);

        std::string content = extractText(node);

        result.push_back({tagName, content});

        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            GumboNode* child = static_cast<GumboNode*>(children->data[i]);
            auto childResult = parseTags(child);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }
    }

    return result;
}

std::vector<std::vector<std::string>> parseHtml(std::string body) {
    GumboOutput* output = gumbo_parse(body.c_str());
    GumboNode* root = output->root;

    std::vector<std::vector<std::string>> result = parseTags(root);
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    return result;
}