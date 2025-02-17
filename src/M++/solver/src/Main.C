// file:   Main.C
// author: Jiping Xin

#include "m++.h" 
#include "mpi.h"

#ifdef DCOMPLEX
#error undef DCOMPLEX in src/Compiler.h
#endif

void SlicePhaseTestMain (int argc, char** argv);
void InfillTestMain ();
void AMMain ();
void PoissonMain ();
void HeatMain ();
void ElasticityMain ();
void TElasticityMain ();
void TElastoPlasticity2Main ();
void ThermalElastoPlasticityMain ();

void inp2geo ();
void mesh_adaptive_test ();
void mesh_coarsing ();
void mesh_adaptive ();
void mesh_partitioning ();

int main (int argc, char** argv) {
    DPO dpo(&argc,&argv);
    string Model = "test";
    ReadConfig(Settings,"Model",Model);
    if (Model == "SlicePhaseTest") SlicePhaseTestMain(argc, argv);
    if (Model == "InfillTest") InfillTestMain();
    if (Model == "Poisson") PoissonMain();
    if (Model == "Heat") HeatMain();
    if (Model == "Elasticity") ElasticityMain();
    if (Model == "TElasticity") TElasticityMain();
    if (Model == "TElastoPlasticity2") TElastoPlasticity2Main();
    if (Model == "ThermalElastoPlasticity") ThermalElastoPlasticityMain();
    
    if (Model == "inp2geo") inp2geo();
    if (Model == "meshcoarsing") mesh_coarsing();
    if (Model == "meshadaptive") mesh_adaptive();
    if (Model == "meshpartitioning") mesh_partitioning();
    if (Model == "meshadaptivetest") mesh_adaptive_test();
    return 0;
}
