//
//  CollisionTest.cpp
//  cross
//
//  Created by YoBiya on 2014/01/26.
//
//

#include <gtest/gtest.h>

#include "CollisionDetection.h"
#include "CollisionEventListener.h"

using namespace Cross::Stage;

TEST(Collision, IsCollide) {
	CollisionArea area1(0.0f, 0.0f, 10.0f, 10.0f);
	CollisionArea area2(5.0f, 5.0f, 10.0f, 10.0f);
	CollisionArea area3(-15.0f, -5.0f, 10.0f, 10.0f);
	CollisionArea area4(-15.0f, -5.0f, 10.0f, 10.0f);
	CollisionArea area5(10.0f, 10.0f, 20.0f, 20.0f);
	CollisionArea area6(12.0f, 12.0f, 10.0f, 10.0f);

	ASSERT_TRUE(CollisionDetection::isCollide(area1, area2));	// 一部が重なっている
	ASSERT_FALSE(CollisionDetection::isCollide(area1, area3));	// 重なっていない
	ASSERT_TRUE(CollisionDetection::isCollide(area3, area4));	// 同じ位置と大きさの範囲が重なっている
	ASSERT_TRUE(CollisionDetection::isCollide(area5, area6));	// 大きな範囲の内側に小さな範囲が入っている
	ASSERT_TRUE(CollisionDetection::isCollide(area6, area5));	// 小さな範囲が大きな範囲の内側に入っている
}

TEST(Collision, Register) {
	CollisionDetection collisionDitection;
	ASSERT_EQ(0, collisionDitection.count());	// 最初は何も登録されていない

	CollisionArea::Ptr area1 = CollisionArea::newSharedPtr(0.0f, 0.0f, 10.0f, 10.0f);
	CollisionArea::Ptr area2 = CollisionArea::newSharedPtr(5.0f, 5.0f, 10.0f, 10.0f);

	collisionDitection.add(area1);
	collisionDitection.add(area2);
	ASSERT_EQ(2, collisionDitection.count());	// 2つのコリジョンが登録された

	collisionDitection.remove(area1);
	ASSERT_EQ(1, collisionDitection.count());	// 1つのコリジョンが削除された
}

TEST(Collision, DISABLED_Collide) {
	CollisionDetection collisionDitection;

	bool isCollide1 = false;
	bool isCollide2 = false;

	CollisionArea::Ptr area1 = CollisionArea::newSharedPtr(0.0f, 0.0f, 10.0f, 10.0f);
	CollisionArea::Ptr area2 = CollisionArea::newSharedPtr(5.0f, 5.0f, 10.0f, 10.0f);
	area1->addEventListener(CollisionEventListener::newSharedPtr());
	area2->addEventListener(CollisionEventListener::newSharedPtr());

	collisionDitection.add(area1);
	collisionDitection.add(area2);

	// 衝突判定を行う
	collisionDitection.ditect();

	ASSERT_TRUE(isCollide1);
	ASSERT_TRUE(isCollide2);
}
