//
//  CollisionArea.h
//  cross
//
//  Created by YoBiya on 2014/03/30.
//
//

#ifndef __cross__CollisionArea__
#define __cross__CollisionArea__

#include <iostream>

#include "CollisionEventListener.h"

namespace Cross {
	namespace Stage {

/**
 * @brief 衝突範囲
 */
struct CollisionArea {
public:
	typedef std::shared_ptr<CollisionArea> Ptr;

	float x, y, w, h;

public:
	CollisionArea(float x_, float y_, float w_, float h_);

	void addEventListener(CollisionEventListener::Ptr eventListener);

	static Ptr newSharedPtr(float x, float y, float w, float h);
};

	}	// namespace Stage
}	// namespace Cross

#endif /* defined(__cross__CollisionArea__) */
