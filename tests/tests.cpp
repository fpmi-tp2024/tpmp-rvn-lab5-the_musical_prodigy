#include <gtest/gtest.h>
#include "../include/Model/Model.h"
#include "../include/Model/User.h"

TEST(ValidateUsers, ValidationTrue) {
	try {
        	Model *model = new Model();
		model->addDatabase("test.db");
        	User *user = new User(USER, "user1", "0b14d501a594442a01c6859541bcb3e8164d183d32937b851835442f69d5c94e");
        	ASSERT_TRUE(model->hasUserWithLogin("user1"));
        	delete model;
        	delete user;
    } catch (const std::exception& e) {
    	std::cerr << "Exception caught: " << e.what() << std::endl;
        FAIL();
    }
}

int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}




