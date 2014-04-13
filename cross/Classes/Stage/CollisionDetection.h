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
#include <forward_list>

#include "CollisionArea.h"

namespace Cross {
	namespace Stage {

/**
 * @brief 衝突判定クラス
 */
class CollisionDetection {
	private:
	std::forward_list<CollisionArea::Ptr> _collisionList;

	public:
		CollisionDetection();

		void add(CollisionArea::Ptr collision);
		void remove(CollisionArea::Ptr collision);
		int count();
		void ditect();

		static bool isCollide(CollisionArea &lhs, CollisionArea &rhs);
};

	}	// namespace Stage
}	// namespace Cross

#endif /* defined(__cross__CollisionManager__) */
