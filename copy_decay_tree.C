#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TString.h"
#include <vector>
#include <iostream>
#include "TTree.h"
#include "TBranch.h"

using namespace std;



int copy_decay_tree()
{
    
    
    TFile *fout = new TFile("MC2018_MagDown_21513012_withbckg.root", "update");
    TDirectoryFile *td= (TDirectoryFile*)fout->Get("Tau23MuTau23Mu_Tuple");
    TTree *Tout =(TTree*) td->Get("DecayTree");


    Double_t mu1;
    Double_t mu2;
    Double_t mu3;

    Double_t cone_1;
    Double_t cone_2;
    Double_t cone_3;

    Double_t tau_PT;
    Double_t tau_FD_OWNPV;


    TBranch *mu1_TRACK_CHI2NDOF;
    TBranch *mu2_TRACK_CHI2NDOF;
    TBranch *mu3_TRACK_CHI2NDOF;

    TBranch *tau_ConeMultMuon_1;
    TBranch *tau_ConeMultMuon_2;
    TBranch *tau_ConeMultMuon_3;

    TBranch *br_tau_PT;
    TBranch *br_tau_FD_OWNPV;


    Tout->SetBranchAddress("mup1_TRACK_CHI2NDOF", &mu1, &mu1_TRACK_CHI2NDOF);
    Tout->SetBranchAddress("mum_TRACK_CHI2NDOF", &mu2, &mu2_TRACK_CHI2NDOF);
    Tout->SetBranchAddress("mup2_TRACK_CHI2NDOF", &mu3, &mu3_TRACK_CHI2NDOF);

    Tout->SetBranchAddress("tau_ConeMultMuon_1", &cone_1, &tau_ConeMultMuon_1);
    Tout->SetBranchAddress("tau_ConeMultMuon_2", &cone_2, &tau_ConeMultMuon_2);
    Tout->SetBranchAddress("tau_ConeMultMuon_3", &cone_3, &tau_ConeMultMuon_3);

    Tout->SetBranchAddress("tau_PT", &tau_PT, &br_tau_PT);
    Tout->SetBranchAddress("tau_FD_OWNPV", &tau_FD_OWNPV, &br_tau_FD_OWNPV);


    TFile fin("selected_data.root", "update");
    TTree Tin("DecayTree", "DecayTree");


    Double_t mup1;
    Double_t mum;
    Double_t mup2;

    Double_t CONE_1;
    Double_t CONE_2;
    Double_t CONE_3;

    Double_t TAU_PT;
    Double_t TAU_FD;

    Tin.Branch("mup1_TRACK_CHI2NDOF", &mup1, "mup1_TRACK_CHI2NDOF/D");
    Tin.Branch("mum_TRACK_CHI2NDOF",  &mum,  "mum_TRACK_CHI2NDOF/D");
    Tin.Branch("mup2_TRACK_CHI2NDOF", &mup2, "mup2_TRACK_CHI2NDOF/D");

    Tin.Branch("tau_ConeMultMuon_1", &CONE_1, "tau_ConeMultMuon_1/D");
    Tin.Branch("tau_ConeMultMuon_2", &CONE_2, "tau_ConeMultMuon_2/D");
    Tin.Branch("tau_ConeMultMuon_3", &CONE_3, "tau_ConeMultMuon_3/D");

    Tin.Branch("tau_PT", &TAU_PT, "tau_PT/D");
    Tin.Branch("tau_FD", &TAU_FD, "tau_FD/D");


    int entries=Tout->GetEntries();

    for(int i=0; i< entries; ++i){
        Tout->GetEntry(i);

        mup1 = mu1;
        mum  = mu2;
        mup2 = mu3;

        CONE_1 = cone_1;
        CONE_2 = cone_2;
        CONE_3 = cone_3;

        TAU_PT = tau_PT;
        TAU_FD = tau_FD_OWNPV;

        Tin.Fill();
    }

    Tin.Write();
    // fin->Close();

    cout << "Success\n";
    return 0;
}