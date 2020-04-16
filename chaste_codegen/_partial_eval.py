import sympy as sp
from cellmlmanip.model import VariableDummy


def partial_eval(equations, required_lhs, keep_multiple_usages=True):
    evaluated_eqs = []
    # count usage of variables on rhs of equations
    if keep_multiple_usages:
        usage_count = dict()
        for eq in equations:
            usage_count.setdefault(eq.lhs, 0)
            for var in eq.rhs.atoms(VariableDummy):
                usage_count.setdefault(var, 0)
                usage_count[var] += 1
    # subs in all constants and expressions only used once
    subs_dict = {}
    for eq in equations:
        new_rhs = eq.rhs.xreplace(subs_dict)
        # only apply piecewise_fold if needed to speed things up
        if len(eq.rhs.atoms(sp.Piecewise)) > 0:
            new_rhs = sp.piecewise_fold(new_rhs)
        new_eq = sp.Eq(eq.lhs, new_rhs)
        if new_eq.lhs not in required_lhs and \
                (not keep_multiple_usages or isinstance(new_eq.rhs, sp.numbers.Float) or usage_count[new_eq.lhs] <= 1):
            subs_dict[new_eq.lhs] = new_eq.rhs
        else:
            if not keep_multiple_usages:
                subs_dict[new_eq.lhs] = new_eq.rhs
            evaluated_eqs.append(new_eq)
    return evaluated_eqs
