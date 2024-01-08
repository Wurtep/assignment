#pragma once

#include "INode.hpp"

class Node : public INode {
    public:
        Node(int value )
            : m_value(value) {}
        [[nodiscard]] int value() const override { return m_value; };        
        [[nodiscard]] const std::vector<std::unique_ptr<INode>>& children() const override { return m_children; };
        void addChild(std::unique_ptr<INode> child) { m_children.emplace_back(std::move(child)); };

    private:
        int m_value;
        std::vector<std::unique_ptr<INode>> m_children;
};