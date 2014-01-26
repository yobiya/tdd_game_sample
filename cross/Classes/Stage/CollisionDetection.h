//
//  CollisionManager.h
//  cross
//
//  Created by YoBiya on 2014/01/26.
//
//

#ifndef __cross__CollisionManager__
#define __cross__CollisionManager__

#include <iostream>

namespace Cross {
	namespace Stage {

/**
 * @brief 衝突範囲
 */
class CollisionArea {
private:
	float _x, _y, _w, _h;

public:
	CollisionArea(float x, float y, float w, float h);
};

/**
 * @brief 衝突判定クラス
 */
class CollisionDetection {
public:
	static bool isCollide(CollisionArea *lhs, CollisionArea *rhs);
};

	}	// namespace Stage
}	// namespace Cross

#endif /* defined(__cross__CollisionManager__) */
