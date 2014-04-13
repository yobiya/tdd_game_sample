//
//  CollisionEventListener.h
//  cross
//
//  Created by YoBiya on 2014/03/30.
//
//

#ifndef __cross__CollisionEventListener__
#define __cross__CollisionEventListener__

#include <iostream>

namespace Cross {
	namespace Stage {

class CollisionEventListener {
public:
	typedef std::shared_ptr<CollisionEventListener> Ptr;

	static Ptr newSharedPtr();
};

	}	// namespace Stage
}	// namespace Cross

#endif /* defined(__cross__CollisionEventListener__) */
