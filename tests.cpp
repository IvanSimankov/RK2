#include <gtest/gtest.h>
#include "ConceptualExample01.cpp"  // Include your implementation file

TEST(ConceptualExample01Test, InitialState) {
    ConceptualExample01::Originator originator("State A");
    EXPECT_EQ(originator.getState(), "State A");
}

TEST(ConceptualExample01Test, StateSavingAndRestoring) {
    ConceptualExample01::Originator originator("State A");
    ConceptualExample01::CareTaker caretaker;
    std::shared_ptr<ConceptualExample01::Memento> memento = originator.createMemento();
    caretaker.setMemento(memento);
    
    originator.setState("State B");
    EXPECT_EQ(originator.getState(), "State B");
    
    memento = caretaker.getMemento();
    originator.setMemento(memento);
    EXPECT_EQ(originator.getState(), "State A");
}

TEST(ConceptualExample01Test, StateChanging) {
    ConceptualExample01::Originator originator("State A");
    originator.setState("State C");
    EXPECT_EQ(originator.getState(), "State C");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
