//
//  CollisionDetection.cpp
//  cross
//
//  Created by YoBiya on 2014/01/26.
//
//

#include "CollisionDetection.h"

namespace Cross {
	namespace Stage {

/**
 * @brief コンストラクタ
 *
 * @param x X座標
 * @param y Y座標
 * @param w 幅
 * @param h 高さ
 */
CollisionArea::CollisionArea(float x, float y, float w, float h)
 : _x(x), _y(y), _w(w), _h(h)
{
}

/**
 * @brief 衝突判定
 *
 * @param lhs 衝突範囲
 * @param rhs 衝突範囲
 *
 * @retval true 衝突している
 * @retval false 衝突していない
 */
bool CollisionDetection::isCollide(CollisionArea *lhs, CollisionArea *rhs) {
	return false;
}

	}	// namespace Stage
}	// namespace Cross
