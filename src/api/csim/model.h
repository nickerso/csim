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

#ifndef CSIM_MODEL_H_
#define CSIM_MODEL_H_

#include "csim/csim_export.h"

#include <string>

//! Everything in CSim is in this namespace.
namespace csim {

/**
 * The Model class provides the wrapper which makes a CellML model executable.
 *
 * This class provides the executable wrapper for a given CellML model. All functionality provided by the CellML API
 * is hidden from the user by this class.
 */
class CSIM_EXPORT Model
{
public:
    /**
     * Default constructor.
     *
     * Construct an empty csim::Model.
     */
     Model();

    /**
     * Copy constructor
     * @param src The source model to copy.
     */
     Model(const Model& src);

    /**
     * Destructor.
     */
     ~Model();

    /**
     * Load the CellML model from the specified URL.
     * @param url The URL from which to load the model.
     * @return zero on success, non-zero if the model is not able to be loaded.
     */
     int loadCellmlModel(const std::string& url);

     /**
      * Flag the specified variable as being an input for the purposes of code generation. This implies
      * that the variable will have its value set externally to the CellML model. Variables flagged as inputs will be
      * used via the INPUT array in this model's executable function. Attempting to flag a variable after
      * this CellML model has been instantiated into executable code will raise an error.
      * @param variableId The ID of the variable to set as known. This string should be in the format
      * 'component_name/variable_name'.
      * @return On success, the index of this variable in the executable function's INPUT array (>= 0). On error, a
      * negative status code will be returned.
      */
     int setVariableAsInput(const std::string& variableId);

     /**
      * Flag the specified variable as being an output for the purposes of code generation. This implies
      * that the variable will have its value used externally to the CellML model and result in the given variable
      * having an entry in the OUTPUT array in this model's executable function. Attempting to flag a variable after
      * this CellML model has been instantiated into executable code will raise an error.
      * @param variableId The ID of the variable to set as known. This string should be in the format
      * 'component_name/variable_name'.
      * @return On success, the index of this variable in the executable function's OUTPUT array (>= 0). On error, a
      * negative status code will be returned.
      */
     int setVariableAsOutput(const std::string& variableId);

    /**
     * Check if this model is able to be compiled into an executable form.
     * @return True if a suitable CellML model has been loaded; false otherwise.
     */
     bool isModelInstantiated() const;

private:
    /**
     * Internal representation of the CellML model.
     */
    void* mModelDefinition;
};

} // namespace csim

#endif // CSIM_MODEL_H_
