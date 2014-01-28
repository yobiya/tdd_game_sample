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
CollisionArea::CollisionArea(float x_, float y_, float w_, float h_)
 : x(x_), y(y_), w(w_), h(h_)
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
bool CollisionDetection::isCollide(CollisionArea &lhs, CollisionArea &rhs) {
	const float selfLeft = lhs.x;
	const float selfTop = lhs.y;
	const float selfRight = selfLeft + lhs.w;
	const float selfBottom = selfTop + lhs.h;
	const float otherLeft = rhs.x;
	const float otherTop = rhs.y;
	const float otherRight = otherLeft + rhs.w;
	const float otherBottom = otherTop + rhs.h;
	
	if(selfLeft > otherRight) {	return false;	}	// 判定対象の範囲は自分の範囲よりも左側にある
	if(selfTop > otherBottom) {	return false;	}	// 判定対象の範囲は自分の範囲よりも上側にある
	if(selfRight < otherLeft) {	return false;	}	// 判定対象の範囲は自分の範囲よりも右側にある
	if(selfBottom < otherTop) {	return false;	}	// 判定対象の範囲は自分の範囲よりも下側にある
	
	// 判定対象の範囲は自分と重なっている部分がある
	return true;
}

	}	// namespace Stage
}	// namespace Cross
