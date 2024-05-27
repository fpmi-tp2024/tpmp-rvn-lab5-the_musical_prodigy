#include <gtest/gtest.h>
#include "../include/Model/Model.h"
#include "../include/Model/User.h"
#include "../include/Model/CD.h"
#include "../include/Model/Operation.h"
#include <vector>

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

TEST(ValidateUser2, ValidationTrue) {
	try {
        	Model *model = new Model();
		model->addDatabase("test.db");
        	User *user = new User(USER, "user1", "0b14d501a594442a01c6859541bcb3e8164d183d32937b851835442f69d5c94e");
        	ASSERT_TRUE(model->hasUser(*user));
        	delete model;
        	delete user;
    } catch (const std::exception& e) {
    	std::cerr << "Exception caught: " << e.what() << std::endl;
        FAIL();
    }
}

TEST(addDataBase, DBSuccess) {
        Model *model = new Model();
        ASSERT_TRUE(model->addDatabase("test.db"));
        delete model;
}

TEST(canBuyCD, CDSucess) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_TRUE(model->canBuyCD(1));
        delete model;
}

TEST(canBuyCD, CDSucess2) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_TRUE(model->canBuyCD(2));
        delete model;
}

TEST(canBuyCD, CDFail) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_FALSE(model->canBuyCD(4));
        delete model;
}

TEST(canBuyCD2, CDSucess1_1) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_TRUE(model->canBuyCD(1, 10));
        delete model;
}

TEST(canBuyCD2, CDSucess1_2) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_TRUE(model->canBuyCD(1, 90));
        delete model;
} 
TEST(canBuyCD2, CDSucess2_2) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_TRUE(model->canBuyCD(2, 50));
        delete model;
} 

TEST(canBuyCD2, CDFail) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_FALSE(model->canBuyCD(4, 7));
        delete model;
} 

TEST(availableCDsInfo, InfoSize) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(3, model->availableCDsInfo().size());
        delete model;
} 

TEST(bestSellingCDInfo, CDCode) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(3, model->bestSellingCDInfo().getCDCode());
        delete model;
} 

TEST(getMostPopularSingerSoldCDsAmount, CDAmount) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(35, model->getMostPopularSingerSoldCDsAmount());
        delete model;
} 

TEST(getSoldCDsAmount, CDAmount) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(25, model->getSoldCDsAmount(3, "2024-01-02", "2024-01-18"));
        delete model;
}

TEST(getSoldCDsAmount, CDAmountFail) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(-1, model->getSoldCDsAmount(4, "2024-01-02", "2024-01-18"));
        delete model;
}

TEST(getSoldAndLeftCDSortedDescDiff, CDSold) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ("22", model->getSoldAndLeftCDSortedDescDiff()[0][1]);
        delete model;
}

TEST(getSoldAndLeftCDSortedDescDiff, CDInStock) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ("93", model->getSoldAndLeftCDSortedDescDiff()[0][2]);
        delete model;
}

TEST(getSoldCDsNumberAndProfitByEachAuthor, CDAuthorName) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ("Tyler Joseph", model->getSoldCDsNumberAndProfitByEachAuthor()[4][0]);
        delete model;
}

TEST(getSoldCDsNumberAndProfitByEachAuthor, CDSoldByAuthor) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ("35", model->getSoldCDsNumberAndProfitByEachAuthor()[0][1]);
        delete model;
}
TEST(getSoldCDsNumberAndProfitByEachAuthor, CDProfitByAuthor) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ("453.250000", model->getSoldCDsNumberAndProfitByEachAuthor()[0][2]);
        delete model;
}
  
  
TEST(getReceivedAndSoldCDAmountByEachCD, CDSoldByPeriod) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(22 , model->getReceivedAndSoldCDAmountByEachCD("2024-01-01", "2024-04-18")[0][1]);
        delete model;
}

TEST(getSoldCDsAmountAndProfit, CDSoldByID) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(453.25, model->getSoldCDsAmountAndProfit(3, "2024-01-02", "2024-04-18")[0]);
        delete model;
}

TEST(getSoldCDsAmountAndProfit, CDSoldByID2) {
        Model *model = new Model();
        model->addDatabase("test.db");
        ASSERT_EQ(35, model->getSoldCDsAmountAndProfit(3, "2024-01-02", "2024-04-18")[1]);
        delete model;
}

TEST(addNewUser, AddUserSuccess) {
        Model *model = new Model();
        model->addDatabase("test.db");
        User *newUser = new User(USER, "newUser", "newPassword");
        ASSERT_TRUE(model->addNewUser(*newUser));
        delete model;
        delete newUser;
}

TEST(addNewUser, AddUserFail) {
        Model *model = new Model();
        model->addDatabase("test.db");
        User *newUser = new User(USER, "user1", "newPassword");
        ASSERT_FALSE(model->addNewUser(*newUser));
        delete model;
        delete newUser;
}


TEST(addOrBuyCD, SellCDSuccess) {
        Model *model = new Model();
        model->addDatabase("test.db");
        Operation op(OperationCode::SELL, 1, "2024-05-26", 15);
    	Operation op2(OperationCode::SELL, 3, "2024-05-26", 10);
    	std::vector<Operation> vect;
    	vect.push_back(op);
    	vect.push_back(op2);
        ASSERT_TRUE(model->addOrBuyCD(vect));
        delete model;
     
}

TEST(addOrBuyCD, SellCDFail) {
        Model *model = new Model();
        model->addDatabase("test.db");
        Operation op(OperationCode::SELL, 1, "2024-05-26", 10);
    	Operation op2(OperationCode::SELL, 3, "2024-05-26", 150);
    	std::vector<Operation> vect;
    	vect.push_back(op);
    	vect.push_back(op2);
        ASSERT_FALSE(model->addOrBuyCD(vect));
        delete model;
     
}

TEST(addOrBuyCD, GetCDSuccess) {
        Model *model = new Model();
        model->addDatabase("test.db");
        Operation op(OperationCode::RECEIVE, 1, "2024-05-26", 15);
    	Operation op2(OperationCode::RECEIVE, 3, "2024-05-26", 10);
    	std::vector<Operation> vect;
    	vect.push_back(op);
    	vect.push_back(op2);
        ASSERT_TRUE(model->addOrBuyCD(vect));
        delete model;
}

TEST(addOrBuyCD, GetCDFail) {
    Model* model = new Model();
    model->addDatabase("test.db");
    Operation op(OperationCode::RECEIVE, 1, "2024-05-27", 10);
    Operation op2(OperationCode::RECEIVE, 4, "2024-05-27", 15);
    std::vector<Operation> vect;
    vect.push_back(op);
    vect.push_back(op2);
    ASSERT_FALSE(model->addOrBuyCD(vect));
    delete model;
}

int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

