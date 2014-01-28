//
//  CollisionTest.cpp
//  cross
//
//  Created by YoBiya on 2014/01/26.
//
//

#include <gtest/gtest.h>

#include "CollisionDetection.h"

using namespace Cross::Stage;

TEST(Collision, isCollide) {
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

