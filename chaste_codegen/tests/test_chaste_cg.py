import logging
import os
import chaste_codegen as cg
import pytest
import cellmlmanip
import chaste_codegen.tests.chaste_test_utils as test_utils

# Show more logging output
LOGGER = logging.getLogger(__name__)
LOGGER.setLevel(logging.DEBUG)


def get_models(reference_folder = 'chaste_reference_models'):
    """ Load all models if they haven't been loaded yet"""
    return test_utils.load_chaste_models(model_types=['Normal', 'Opt', 'Cvode'],
                                         reference_folder=reference_folder)


def chaste_normal_models():
    """ Load all Normal models"""
    return [model for model in get_models() if model['model_type'] == 'Normal']


def chaste_opt_models():
    """ Load all Opt models"""
    return [model for model in get_models() if model['model_type'] == 'Opt']


def chaste_cvode_models():
    """ Load all Opt models"""
    return [model for model in get_models() if model['model_type'] == 'Cvode']


def chaste_all_normal_models():
    """ Load all Normal models"""
    return [model for model in get_models(reference_folder='cronjob_reference_models') if model['model_type'] == 'Normal']


def chaste_all_opt_models():
    """ Load all Opt models"""
    return [model for model in get_models(reference_folder='cronjob_reference_models') if model['model_type'] == 'Opt']


def chaste_all_cvode_models():
    """ Load all Opt models"""
    return [model for model in get_models(reference_folder='cronjob_reference_models') if model['model_type'] == 'Cvode']


@pytest.mark.cronjob
@pytest.mark.parametrize(('model'), chaste_all_cvode_models(), scope='function')
def test_Cvode_cronjob(tmp_path, model, request):
    """ Check generation of Cvode models against reference"""
    if request.config.option.markexpr != 'cronjob':
        pytest.skip('Skip if not explicitly set to run cronjob with -m cronjob')
    test_Cvode(tmp_path, model)


@pytest.mark.cronjob
@pytest.mark.parametrize(('model'), chaste_all_normal_models(), scope='function')
def test_Normal_cronjob(tmp_path, model, request):
    """ Check generation of Normal models against reference"""
    if request.config.option.markexpr != 'cronjob':
        pytest.skip('Skip if not explicitly set to run cronjob with -m cronjob')
    test_Normal(tmp_path, model)


@pytest.mark.cronjob
@pytest.mark.parametrize(('model'), chaste_opt_models(), scope='function')
def test_Opt_cronjob(tmp_path, model, request):
    """ Check generation of Opt models against reference"""
    if request.config.option.markexpr != 'cronjob':
        pytest.skip('Skip if not explicitly set to run cronjob with -m cronjob')
    test_Opt(tmp_path, model)


@pytest.mark.parametrize(('model'), chaste_cvode_models())
def test_Cvode(tmp_path, model):
    """ Check generation of Cvode models against reference"""
    # Note: currently only implemented partia eval
    class_name = 'Cell' + model['model_name_from_file'] + 'FromCellML'
    LOGGER.info('Converting: Cvode: ' + class_name + '\n')
    # Generate chaste code
    chaste_model = cg.CvodeChasteModel(cellmlmanip.load_model(model['model']), model['model_name_from_file'],
                                       class_name=class_name)
    chaste_model.generate_chaste_code()
    # Comprare against referene
    test_utils.compare_model_against_reference('Cvode', chaste_model, tmp_path, model['expected_hpp_path'],
                                               model['expected_cpp_path'])


@pytest.mark.parametrize(('model'), chaste_normal_models())
def test_Normal(tmp_path, model):
    """ Check generation of Normal models against reference"""
    class_name = 'Cell' + model['model_name_from_file'] + 'FromCellML'
    LOGGER.info('Converting: Normal: ' + class_name + '\n')
    # Generate chaste code
    chaste_model = cg.NormalChasteModel(cellmlmanip.load_model(model['model']), model['model_name_from_file'],
                                        class_name=class_name)
    chaste_model.generate_chaste_code()
    # Comprare against referene
    test_utils.compare_model_against_reference('Normal', chaste_model, tmp_path, model['expected_hpp_path'],
                                               model['expected_cpp_path'])


@pytest.mark.parametrize(('model'), chaste_opt_models())
def test_Opt(tmp_path, model):
    """ Check generation of Opt models against reference"""
    # Note: currently only implemented partia eval
    class_name = 'Cell' + model['model_name_from_file'] + 'FromCellML'
    LOGGER.info('Converting: Opt: ' + class_name + '\n')
    # Generate chaste code
    chaste_model = cg.OptChasteModel(cellmlmanip.load_model(model['model']), model['model_name_from_file'],
                                     class_name=class_name)
    chaste_model.generate_chaste_code()
    # Comprare against referene
    test_utils.compare_model_against_reference('Opt', chaste_model, tmp_path, model['expected_hpp_path'],
                                               model['expected_cpp_path'])


def test_dymaic_model(tmp_path):
    tmp_path = str(tmp_path)
    LOGGER.info('Converting: Normal Dynamic luo_rudy_1994\n')
    model_file = \
        os.path.join(cg.DATA_DIR, 'tests', 'cellml', 'luo_rudy_1994.cellml')
    chaste_model = cellmlmanip.load_model(model_file)
    chaste_model = cg.NormalChasteModel(chaste_model,
                                        'dynamic_luo_rudy_1994',
                                        class_name='Dynamicluo_rudy_1994FromCellML',
                                        dynamically_loadable=True)
    chaste_model.generate_chaste_code()
    expected_hpp_path = os.path.join(tmp_path, 'dynamic_luo_rudy_1994.hpp')
    expected_cpp_path = os.path.join(tmp_path, 'dynamic_luo_rudy_1994.cpp')
    # Comprare against referene
    test_utils.compare_model_against_reference('Normal', chaste_model, tmp_path, expected_hpp_path,
                                               expected_cpp_path)


def test_expose_annotated_variables(tmp_path):
    tmp_path = str(tmp_path)
    LOGGER.info('Testing expose_annotated_variables option\n')
    model_file = \
        os.path.join(cg.DATA_DIR, 'tests', 'cellml', 'aslanidi_model_2009.cellml')
    chaste_model = cellmlmanip.load_model(model_file)

    chaste_model = cg.NormalChasteModel(chaste_model,
                                        'expose_annotated_variables_cellaslanidi_model_2009',
                                        class_name='Cellaslanidi_model_2009FromCellML',
                                        expose_annotated_variables=True)

    chaste_model.generate_chaste_code()
    expected_hpp_path = os.path.join(tmp_path, 'expose_annotated_variables_cellaslanidi_model_2009.hpp')
    expected_cpp_path = os.path.join(tmp_path, 'expose_annotated_variables_cellaslanidi_model_2009.cpp')
    # Comprare against referene
    test_utils.compare_model_against_reference('Normal', chaste_model, tmp_path,
                                               expected_hpp_path, expected_cpp_path)


def test_missing_capacitance(tmp_path):
    tmp_path = str(tmp_path)
    LOGGER.info('Testing missing capacitance\n')
    model_file = \
        os.path.join(cg.DATA_DIR, 'tests', 'cellml', 'pandit_model_2001_epi_old_no_capacitance.cellml')
    chaste_model = cellmlmanip.load_model(model_file)

    with pytest.raises(AssertionError) as error:
        chaste_model = cg.NormalChasteModel(chaste_model,
                                            'pandit_model_2001_epi_old_no_capacitance',
                                            class_name='pandit_model_2001_epi_old_no_capacitance')
    assert str(error.value) == \
        'Membrane capacitance is required to be able to apply conversion to stimulus current!'


def test_wrong_units_time(capsys, tmp_path):
    tmp_path = str(tmp_path)
    LOGGER.info('Testing wrong units for time\n')
    model_file = \
        os.path.join(cg.DATA_DIR, 'tests', 'cellml', 'test_wrong_units_time_odes.cellml')
    chaste_model = cellmlmanip.load_model(model_file)

    with pytest.raises(AssertionError) as error:
        chaste_model = cg.NormalChasteModel(chaste_model,
                                            'test_wrong_units_time_odes',
                                            class_name='test_wrong_units_time_odes')
    warning = 'Incorrect definition of time variable (time needs to be dimensionally equivalent to second)'
    assert str(error.value) == warning


def test_wrong_units_voltage(capsys, tmp_path):
    tmp_path = str(tmp_path)
    LOGGER.info('Testing wrong units for time\n')
    model_file = \
        os.path.join(cg.DATA_DIR, 'tests', 'cellml', 'test_wrong_units_voltage.cellml')
    chaste_model = cellmlmanip.load_model(model_file)

    with pytest.raises(AssertionError) as error:
        chaste_model = cg.NormalChasteModel(chaste_model,
                                            'test_wrong_units_voltage',
                                            class_name='test_wrong_units_voltage')
    warning = \
        'Incorrect definition of membrane_voltage variable '\
        '(units of membrane_voltage needs to be dimensionally equivalent to Volt)'
    assert str(error.value) == warning
