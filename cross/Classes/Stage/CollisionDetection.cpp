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
 */
CollisionDetection::CollisionDetection() {
}

/**
 * @brief コリジョンを登録
 *
 * @param collision コリジョン
 */
void CollisionDetection::add(CollisionArea::Ptr collision) {
	_collisionList.push_front(collision);
}

/**
 * @brief コリジョンの登録を削除
 *
 * @param collision コリジョン
 */
void CollisionDetection::remove(CollisionArea::Ptr collision) {
	_collisionList.remove(collision);
}

/**
 * @brief 登録されているコリジョンの数を取得
 *
 * @return 登録されているコリジョンの数
 */
int CollisionDetection::count() {
	return static_cast<int>(distance(_collisionList.begin(), _collisionList.end()));
}

/**
 * @brief 登録されているコリジョンの衝突判定を行う
 */
void CollisionDetection::ditect() {
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
