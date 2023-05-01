/*--------------------------------------------------------------------------------------*/
/*----------------------- Analysis Plot For Tau pair production ------------------------*/
/*--------------------------------------------------------------------------------------*/
// Author: Gajendra Gurung
// Date  : May 1, 2023
//

#define electronPositron_cxx
#include "electronPositron.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void electronPositron::Loop()
{
//   In a ROOT session, you can do:
//      root> .L electronPositron.C
//      root> electronPositron t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//      root> t.PlotTauDis();
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
void electronPositron::PlotTauDis()
{
	if (fChain == 0) return;
	Long64_t nEntries = fChain->GetEntriesFast();
	cout << "This root file has : " << nEntries << " entries." << endl;
	
	TH1D* EnergyDis = new TH1D("EnergyDis", "Energy distribution of #tau's produced from e+e- annihilation; Energy [GeV]; Count/ 2 GeV", 45, 0, 91);
	EnergyDis ->SetLineColor(37);
	TH1D* AngularDisPhi = new TH1D("AngularDisPhi", "Angular distribution of #tau's produced from e+e- annihilation; #theta [rad]; Count/ 42 mrad", 75, 0, 3.15);
	AngularDisPhi->SetLineColor(37);
	TH1D* AngularDisTheta = new TH1D("AngularDisTheta", "Angular distribution of #tau's produced from e+e- annihilation; #theta [rad]; Count/ 42 mrad", 75, 0, 3.15);
	AngularDisTheta->SetLineColor(46);


	for(Int_t i = 0; i < nEntries; i++)
	{
		fChain->GetEntry(i);
		if( id != 15) continue;
		EnergyDis->Fill(Ene);
		AngularDisPhi->Fill(Phi);
		AngularDisTheta->Fill(Theta);
	}
	auto c = new TCanvas("c","c");
	EnergyDis->Draw("e1p");
	c->SetLogy(1);
	
	auto c1 = new TCanvas("c1","c1");
	AngularDisTheta->Draw("e1p");
	AngularDisPhi->Draw("e1p same");
	auto legend = new TLegend();
	legend->SetHeader("Angular Distribution","C");
	legend->AddEntry(AngularDisTheta,"Azimuthal #theta","le");
	legend->AddEntry(AngularDisPhi,"Polar #phi","le");
	legend->Draw();
	gStyle->SetOptStat(0);
	//	c->SetLogy(1);
	
	
	TFile f("Asymm_Distribution.root","recreate");
	EnergyDis->Write();
	AngularDisTheta->Write();
	AngularDisPhi->Write();
}


//void electronPositron::AllParticles()
//{
//	if (fChain == 0) return;
//	Long64_t nEntries = fChain->GetEntriesFast();
//	cout << "This root file has : " << nEntries << " entries." << endl;
//	TH1S* AllParticles = new TH1S("AllParticles", "List of All the Particles Produced", 15, 0, 15); AllParticles ->SetLineColor(37);
//	for(Int_t i = 0; i < nEntries; i++){
//		fChain->GetEntry(i);
//		AllParticles->Fill(name);
//	}
//	auto c = new TCanvas("c","c");
//	AllParticles->Draw();
//	c->SetLogy(1);
//}
