#include "gtest/gtest.h"

#include "csim/model.h"
#include "csim/error_codes.h"

// generated with test resource locations
#include "test_resources.h"

TEST(Model, new_model) {
    csim::Model model;
    EXPECT_FALSE(model.isModelInstantiated());
}

TEST(Model, load_nonexisting_model) {
    csim::Model model;
    EXPECT_EQ(csim::UNABLE_TO_LOAD_MODEL_URL,
              model.loadCellmlModel("http://example.com/this.cellml.file.should.never.exist.xml"));
}

TEST(Model, load_non_cellml_model) {
    csim::Model model;
    EXPECT_EQ(csim::UNABLE_TO_LOAD_MODEL_URL,
              model.loadCellmlModel(TestResources::getLocation(TestResources::SBML_MODEL_RESOURCE)));
}

TEST(Model, load_invalid_cellml_model) {
    csim::Model model;
    EXPECT_EQ(csim::UNABLE_TO_LOAD_MODEL_URL,
              model.loadCellmlModel(TestResources::getLocation(TestResources::CELLML_INVALID_MODEL_RESOURCE)));
}

TEST(Model, load_valid_cellml_model) {
    csim::Model model;
    EXPECT_EQ(csim::CSIM_OK,
              model.loadCellmlModel(TestResources::getLocation(TestResources::CELLML_SINE_MODEL_RESOURCE)));
}

TEST(Model, load_valid_cellml_model_with_imports) {
    csim::Model model;
    EXPECT_EQ(csim::CSIM_OK,
              model.loadCellmlModel(TestResources::getLocation(TestResources::CELLML_SINE_IMPORTS_MODEL_RESOURCE)));
}
