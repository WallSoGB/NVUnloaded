#pragma once

#include "NiMemObject.hpp"

template <class T_Data>
class NiTAbstractPoolAllocator {
public:
    class AllocNode : public NiMemObject {
    public:
        AllocNode*  m_pkNext;
        void*       m_pkData;
        T_Data      m_element;
    };
};