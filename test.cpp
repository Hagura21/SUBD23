#include "pch.h"
#include "../DL/DoubleList.h"
#include <string>

using namespace std;
	
TEST(TestString, TestPushB)
{
	DoubleList <string> DL2;
	DL2.PushB("Hello");
	DL2.PushB("World");
	EXPECT_EQ(DL2.Size(), 2);
	EXPECT_EQ(DL2.GetB(), "World");
}

TEST(TestString, TestPushF) 
{
	DoubleList <string> DL2;
	DL2.PushF("World");
	DL2.PushF("Hello");
	EXPECT_EQ(DL2.Size(), 2);
	EXPECT_EQ(DL2.GetF(), "Hello");
}

TEST(TestInt, TestPushB) 
{
	DoubleList <int> DL1;
	DL1.PushB(34);
	DL1.PushB(57);
	EXPECT_EQ(DL1.Size(), 2);
	EXPECT_EQ(DL1.GetB(), 57);
}

TEST(TestInt, TestPushF) 
{
	DoubleList <int> DL1;
	DL1.PushF(65);
	DL1.PushF(17);
	EXPECT_EQ(DL1.Size(), 2);
	EXPECT_EQ(DL1.GetF(), 17);
}

TEST(TestInt, TestGet) 
{
	DoubleList <int> DL1;
	DL1.PushB(10);
	DL1.PushB(15);
	DL1.PushB(48);
	DL1.PushB(-4);
	EXPECT_EQ(DL1.Get(2), 48);
	EXPECT_EQ(DL1.Get(3), -4);
	EXPECT_EQ(DL1.Get(0), 10);
}

TEST(TestString, TestGet)
{
	DoubleList <string> DL2;
	DL2.PushB("Hello");
	DL2.PushB("Perfect");
	DL2.PushB("World");
	EXPECT_EQ(DL2.Get(0), "Hello");
}


TEST(TestInt, TestPopFLogicError) 
{
	DoubleList <int> DL1;
	EXPECT_THROW(DL1.PopF(), logic_error);
}

TEST(TestString, TestPopFLogicError)
{
	DoubleList <string> DL2;
	EXPECT_THROW(DL2.PopF(), logic_error);
}

TEST(TestInt, TestPopF)
{
	DoubleList <int> DL1;
	DL1.PushB(23);
	DL1.PushB(37);
	DL1.PopF();
	EXPECT_EQ(DL1.Size(), 1);
}

TEST(TestString, TestPopF)
{
	DoubleList <string> DL2;
	DL2.PushB("Dreams");
	DL2.PushB("Come");
	DL2.PushB("True");
	DL2.PopF();
	EXPECT_EQ(DL2.Size(), 2);
}

TEST(TestInt, TestPopBLogicError) 
{
	DoubleList <int> DL1;
	EXPECT_THROW(DL1.PopB(), logic_error);
}

TEST(TestString, TestPopBLogicError)
{
	DoubleList <string> DL2;
	EXPECT_THROW(DL2.PopB(), logic_error);
}

TEST(TestInt, TestPopB)
{
	DoubleList <int> DL1;
	DL1.PushB(45);
	DL1.PushB(78);
	DL1.PopB();
	EXPECT_EQ(DL1.Size(), 1);
}

TEST(TestString, TestPopB)
{
	DoubleList <string> DL2;
	DL2.PushB("Dreams");
	DL2.PushB("Come");
	DL2.PushB("True");
	DL2.PopB();
	EXPECT_EQ(DL2.Size(), 2);
}

TEST(TestInt, TestRemove)
{
	DoubleList <int> DL1;
	DL1.PushB(15);
	DL1.PushB(23);
	DL1.PushB(67);
	DL1.Remove(1);
	EXPECT_EQ(DL1.Size(), 2);
}

TEST(TestString, TestRemove)
{
	DoubleList <string> DL2;
	DL2.PushB("Dreams");
	DL2.PushB("Come");
	DL2.PushB("True");
	DL2.Remove(0);
	EXPECT_EQ(DL2.Size(), 2);
}

TEST(TestInt, TestAddOutOfRange) 
{
	DoubleList <int> DL1;
	EXPECT_THROW(DL1.Add(14, 4), out_of_range);
}

TEST(TestString, TestAddOutOfRange)
{
	DoubleList <string> DL2;
	EXPECT_THROW(DL2.Add("Worry", 4), out_of_range);
}

TEST(TestInt, TestAdd)
{
	DoubleList <int> DL1;
	DL1.PushB(15);
	DL1.PushB(23);
	DL1.Add(67, 1);
	EXPECT_EQ(DL1.Size(), 3);
}
TEST(TestString, TestAdd) 
{
	DoubleList <string> DL2;
	DL2.PushB("Dreams");
	DL2.PushB("True");
	DL2.Add("Come", 1);
	std::vector<string> a1 = { "Dreams","Come","True"};
	for (size_t i = 0; i < a1.size(); i++)
	{
		EXPECT_TRUE(DL2.Get(i).compare(a1[i]) == 0);
	}
}

TEST(TestInt, TestClean) 
{
	DoubleList <int> DL1;
	DL1.PushB(15);
	DL1.PushB(23);
	DL1.PushB(67);
	EXPECT_NO_FATAL_FAILURE(DL1.Clean());
	EXPECT_EQ(DL1.Size(), 0);
}

TEST(TestString, TestClean) 
{
	DoubleList <string> DL2;
	DL2.PushB("Dreams");
	DL2.PushB("True");
	DL2.PushB("Come");
	EXPECT_NO_FATAL_FAILURE(DL2.Clean());
	EXPECT_EQ(DL2.Size(), 0);
}

int main(int argc, char** argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}