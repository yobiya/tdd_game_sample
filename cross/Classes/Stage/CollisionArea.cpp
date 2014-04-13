//
//  CollisionArea.cpp
//  cross
//
//  Created by YoBiya on 2014/03/30.
//
//

#include "CollisionArea.h"

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
 * @brief 衝突した時に呼ばれるイベントのリスナーを登録する
 *
 * @param eventListener イベントのリスナー
 */
void CollisionArea::addEventListener(CollisionEventListener::Ptr eventListener) {
}

/**
 * @brief shared_ptrを生成
 *
 * @return shared_ptr
 */
CollisionArea::Ptr CollisionArea::newSharedPtr(float x, float y, float w, float h) {
	return CollisionArea::Ptr(new CollisionArea(x, y, w, h));
}

	}	// namespace Stage
}	// namespace Cross
