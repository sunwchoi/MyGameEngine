#pragma once
#include <functional>

#include "vector.hpp"

namespace my
{
    template<typename NodeType>
    class  OneWayTree
    {
    public:
        virtual ~OneWayTree() = default;

        const vector<NodeType*>& GetChildren() const { return _children; }

        void AddChild(NodeType* node)
        {
            _children.push_back(node);
        }

        void Traverse(const std::function<void(const NodeType*)>& func) const {
            func(static_cast<const NodeType*>(this));

            for (auto* child : _children) {
                child->Traverse(func);
            }
        }

    private:
        vector<NodeType*> _children;
    };

    template<typename NodeType>
    class TwoWayTree : public OneWayTree<NodeType>
    {
    public:
        virtual ~TwoWayTree() = default;

        const NodeType* GetParent() const { return _parent; }
        void SetParent(NodeType* node) { _parent = node; }

    private:
        NodeType* _parent;
    };
}
