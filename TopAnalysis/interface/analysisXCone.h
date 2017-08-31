#ifndef _analysisXCone_h_
#define _analysisXCone_h_

#include "TH1.h"
#include "TString.h"
#include "TFile.h"

#include "TopLJets2015/TopAnalysis/interface/SelectionTools.h"

#include <map>

struct analysisXCone_t
{
  Int_t gen_sel, reco_sel;
  Int_t run,event,lumi,cat;
  Int_t nvtx;
  Int_t nw;
  Int_t NJettiness_reco;
  Int_t NJettSlope_reco;
  Int_t NJettiness_gen;
  Int_t NJettSlope_gen;
  Float_t weight[400];
  Float_t tau_reco[10];
  Float_t dtau_reco[10]; 
  Float_t tau_gen[10];
  Float_t dtau_gen[10]; 
  Int_t passSel,gen_passSel;
  Int_t nj, nb;
  Int_t gen_nj, gen_nb;
  Float_t ptpos,  phipos,  ptll,  phill,  mll,  sumpt,  dphill;
  Float_t gen_ptpos, gen_phipos, gen_ptll, gen_phill, gen_mll, gen_sumpt, gen_dphill;
};

void createanalysisXConeTree(TTree *t,analysisXCone_t &tue);
void resetanalysisXCone(analysisXCone_t &tue);
void RunanalysisXCone(TString filename,
                      TString outname,
                      Int_t channelSelection, 
                      Int_t chargeSelection, 
                      SelectionTool::FlavourSplitting flavourSplitting,
                      TH1F *normH, 
                      Bool_t runSysts,
                      std::string systVar,
                      TString era,
                      Bool_t debug,
                      int splitting_start,
                      int splitting_end);
#endif
