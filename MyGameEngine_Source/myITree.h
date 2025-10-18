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

        virtual void AddChild(NodeType* node)
        {
            _children.push_back(node);
        }

        void TraverseSafely(const std::function<void(const NodeType*)>& pre, const std::function<void(const NodeType*)>& post) const {
            pre(static_cast<const NodeType*>(this));

            for (auto* child : _children)
                child->Traverse(pre, post);
         
            pre(static_cast<const NodeType*>(this));
        }

        void Traverse(const std::function<void(NodeType*)>& pre, const std::function<void(NodeType*)>& post) {
            pre(static_cast<NodeType*>(this));

            for (auto* child : _children)
                child->Traverse(pre, post);

            post(static_cast<NodeType*>(this));
        }

    private:
        vector<NodeType*> _children;
    };

    template<typename NodeType>
    class TwoWayTree : public OneWayTree<NodeType>
    {
    public:
        virtual ~TwoWayTree() = default;
        virtual void AddChild(NodeType* node)
        {
	        __super::AddChild(node);
            node->SetParent(static_cast<NodeType*>(this));
        }

        const NodeType* GetParent() const { return _parent; }
        NodeType* GetParent() { return _parent; }
        void SetParent(NodeType* node) { _parent = node; }

    private:
        NodeType* _parent;
    };
}
