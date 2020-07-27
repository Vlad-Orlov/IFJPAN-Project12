void copy_tree(){
    TFile *f = new TFile("MC2018_MagDown_21513012_withbckg.root", "update");
    TTree *T = (TTree*)f->Get("BackgroundTree");

    TLeaf *mu1_chi2 = T->GetLeaf("mu1_TRACK_CHI2NDOF");
    TLeaf *mu2_chi2 = T->GetLeaf("mu2_TRACK_CHI2NDOF");
    TLeaf *mu3_chi2 = T->GetLeaf("mu3_TRACK_CHI2NDOF");

    Float_t mup1_chi2, mup2_chi2, mum_chi2;

    auto new_mu1_chi2 = T->Branch("mup1_TRACK_CHI2NDOF", &mup1_chi2, "mup1_chi2/F");
    auto new_mu2_chi2 = T->Branch("mum_TRACK_CHI2NDOF", &mum_chi2, "mum_chi2/F");
    auto new_mu3_chi2 = T->Branch("mup2_TRACK_CHI2NDOF", &mup2_chi2, "mup2_chi2/F");

    Long64_t nentries = T->GetEntries(); // read the number of entries in the t3
 
    for (Long64_t i = 0; i < nentries; i++) {
        mu1_chi2->GetBranch()->GetEntry(i);
        mu2_chi2->GetBranch()->GetEntry(i);
        mu3_chi2->GetBranch()->GetEntry(i);

        mup1_chi2 = mu1_chi2->GetValue();
        mum_chi2  = mu2_chi2->GetValue();
        mup2_chi2 = mu3_chi2->GetValue();

        new_mu1_chi2->Fill();
        new_mu2_chi2->Fill();
        new_mu3_chi2->Fill();

    }
 
    T->Write();


    cout << "Success\n";
}