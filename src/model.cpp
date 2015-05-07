/*
Copyright 2015 University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.Some license of other
*/
#include <iostream>

#include "csim/model.h"
#include "csim/error_codes.h"
#include "cellml_model_definition.h"

namespace csim {

Model::Model() : mModelDefinition(0)
{
}

Model::Model(const Model &src)
{
    mModelDefinition = src.mModelDefinition;
}

Model::~Model()
{
    if (mModelDefinition)
    {
        // TODO: cast and then delete model definition
    }
}

int Model::loadCellmlModel(const std::string &url)
{
    if (mModelDefinition) delete static_cast<CellmlModelDefinition*>(mModelDefinition);
    std::cout << "Loading CellML Model URL: " << url << std::endl;
    CellmlModelDefinition* cellml = new CellmlModelDefinition();
    int success = cellml->loadModel(url);
    if (success != 0)
    {
        std::cerr << "Model::loadCellmlModel: Unable to load the model: " << url << std::endl;
        mModelDefinition = NULL;
        return UNABLE_TO_LOAD_MODEL_URL;
    }
    mModelDefinition = static_cast<void*>(cellml);
    return CSIM_OK;
}

bool Model::isModelInstantiated() const
{
    if (mModelDefinition) return true;
    return false;
}

} // namespace csim