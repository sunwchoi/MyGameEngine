#pragma once
#include "myWidget.h"

namespace my
{
    class UIEdit;

    class EditorObjectViewWidget :
        public Widget
    {
        GENERATED_WIDGET_BODY()
    public:
        EditorObjectViewWidget();
        ~EditorObjectViewWidget();

        virtual void Construct() override;

    public:
        UIEdit* posXEdit;
        UIEdit* posYEdit;
        UIEdit* posZEdit;
    };
}

