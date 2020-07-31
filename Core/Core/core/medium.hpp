﻿#ifndef medium_hpp
#define medium_hpp
#include "header.h"

KAWAII_BEGIN

// 介质
class Medium {
public:
    // Medium Interface
    virtual ~Medium() {}
    //    virtual Spectrum Tr(const Ray &ray, Sampler &sampler) const = 0;
    //    virtual Spectrum Sample(const Ray &ray, Sampler &sampler,
    //                            MemoryArena &arena,
    //                            MediumInteraction *mi) const = 0;
};

// 两个介质的相交处，nullptr表示真空
struct MediumInterface {

    MediumInterface(const Medium* medium) : inside(medium), outside(medium) {

    }

    MediumInterface(const Medium* inside = nullptr, const Medium* outside = nullptr)
        :inside(inside),
        outside(outside) {

    }

    bool IsMediumTransition() const {
        return inside != outside;
    }

    // 内部的介质
    const Medium* inside;

    // 外部的介质
    const Medium* outside;
};

KAWAII_END

#endif /* medium_hpp */