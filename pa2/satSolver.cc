#include "satSolver.h"
#include "minisat/core/SolverTypes.h"
#include "minisat/core/Solver.h"

bool satCallingMiniSat(unsigned int numVar, std::vector<std::vector<int>> &cnf) {
  // your code starts here
  Std::unique_ptr<Minisat::Solver> solver(new Minisat::Solver());
  Minisat::Lit a = Minisat::mklit(solver->newVar());
  solver->addClause(a , b, c);
  solver->solve();


  return true;
}

int main()
{

  return 0;
}
