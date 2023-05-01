//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Apr 29 22:25:13 2023 by ROOT version 6.26/06
// from TTree tree/tree
// found on file: TauProduction_7.5e6.root
//////////////////////////////////////////////////////////

#ifndef electronPositron_h
#define electronPositron_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class electronPositron {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           id;
   Int_t           event;
   Int_t           size;
//   Int_t           no;
   Double_t        m;
   Double_t        px;
   Double_t        py;
   Double_t        pz;
	 Double_t        Ene;
	 Double_t        Phi;
	 Double_t        Theta;
//	 Char_t          name;

   // List of branches
   TBranch        *b_id;   //!
   TBranch        *b_event;   //!
   TBranch        *b_size;   //!
   TBranch        *b_no;   //!
   TBranch        *b_m;   //!
   TBranch        *b_px;   //!
   TBranch        *b_py;   //!
   TBranch        *b_pz;   //!
	 TBranch        *b_Ene;
	 TBranch         *b_Phi;
	 TBranch         *b_Theta;
//	TBranch         *b_name;

   electronPositron(TTree *tree=0);
   virtual ~electronPositron();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
	 virtual void     PlotTauDis();
	// virtual void     AllParticles();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef electronPositron_cxx
electronPositron::electronPositron(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TauProd_Asymmetrical_1e6.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TauProd_Asymmetrical_1e6.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

electronPositron::~electronPositron()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t electronPositron::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t electronPositron::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void electronPositron::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
   fChain->SetBranchAddress("id", &id, &b_id);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("size", &size, &b_size);
//   fChain->SetBranchAddress("no", &no, &b_no);
   fChain->SetBranchAddress("m", &m, &b_m);
   fChain->SetBranchAddress("px", &px, &b_px);
   fChain->SetBranchAddress("py", &py, &b_py);
   fChain->SetBranchAddress("pz", &pz, &b_pz);
	 fChain->SetBranchAddress("Theta", &Theta, &b_Theta);
	 fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
	 fChain->SetBranchAddress("Ene", &Ene, &b_Ene);
//	 fChain->SetBranchAddress("name", &name, &b_name);
   Notify();
}

Bool_t electronPositron::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void electronPositron::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t electronPositron::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef electronPositron_cxx
