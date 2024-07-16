#pragma once

#include <list>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Codec {
    std::vector<char> bytes;

    enum class Status {
        NUL,
        INT,
    };

    std::pair<Status, int> readInt(std::istream &s) {
        char c;
        s.get(c);
        if (s.eof() || c == '\0') return {Status::NUL, 0};
        int bytes = c;
        int val = 0;
        for (int i = 0; i < bytes; ++i) {
            s.get(c);
            val |= (255 & c) << (i * 8);
        }
        return {Status::INT, val};
    }

    void writeInt(std::ostream &s, unsigned int val) {
        int nbytes = 1;
        for (; nbytes <= 4; ++nbytes) {
            bytes[nbytes - 1] = val;
            val >>= 8;
            if (val == 0) break;
        }
        s.put(nbytes);
        for (auto i = 0; i < nbytes; ++i) s.put(bytes[i]);
    }

  public:
    Codec() : bytes(4) {}

    void serialize(std::ostream &s, TreeNode *node) {
        if (node == nullptr) {
            s.put('\0');
            return;
        }
        writeInt(s, node->val);
        serialize(s, node->left);
        serialize(s, node->right);
    }

    std::string serialize(TreeNode *root) {
        std::ostringstream ss;
        serialize(ss, root);
        return ss.str();
    }

    TreeNode *deserialize(std::istream &s) {
        auto [status, val] = readInt(s);
        if (status == Status::NUL) return nullptr;
        auto n = new TreeNode(val);
        n->left = deserialize(s);
        n->right = deserialize(s);
        return n;
    }

    TreeNode *deserialize(std::string data) {
        std::istringstream ss(data);
        return deserialize(ss);
    }
};
