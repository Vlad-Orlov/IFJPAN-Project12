void copy_tree(){
    TFile *f = new TFile("data.root", "update");
    TTree *T = (TTree*)f->Get("T");

    TLeaf *px = T->GetLeaf("px");


    Float_t new_px;

    auto new_px_br = T->Branch("new_px", &new_px, "new_px/F");


    Long64_t nentries = T->GetEntries(); // read the number of entries in the t3
 
    for (Long64_t i = 0; i < nentries; i++) {
        px->GetBranch()->GetEntry(i);
       
        new_px = px->GetValue();

        new_px_br->Fill();

    }
 
    T->Write();


    cout << "Success\n";
}
