/*--------------------------------------------------------------------------------------*/
/*------------------------------------ Analysis Codes ----------------------------------*/
/*--------------------------------------------------------------------------------------*/
// Author: Gajendra Gurung
// Date  : May 1, 2023
//

void analysis(){
	TH1F* AngularDisTheta_sym; TH1F* AngularDisPhi_sym; TH1F* EnergyDis_sym;
	TFile* g = new TFile("Symm_Distribution.root");
	AngularDisTheta_sym = (TH1F*)g -> Get("AngularDisTheta"); AngularDisTheta_sym ->SetLineColor(46);
	EnergyDis_sym = (TH1F*)g -> Get("EnergyDis"); EnergyDis_sym ->SetLineColor(46);
	
	TH1F* AngularDisTheta; TH1F* AngularDisPhi;  TH1F* EnergyDis;
	TFile* h = new TFile("Asymm_Distribution.root");
	AngularDisTheta = (TH1F*)h -> Get("AngularDisTheta");  AngularDisTheta ->SetLineColor(37);
	EnergyDis = (TH1F*)h -> Get("EnergyDis"); EnergyDis ->SetLineColor(37);
	
	gStyle->SetOptStat(0);
	gStyle->SetLegendFont(80);
	
	TCanvas* c = new TCanvas("c", "Angular Distribution");
	AngularDisTheta->Draw("e1p");
	AngularDisTheta_sym->Draw("e1p same");
	
	//auto rp = new TRatioPlot(AngularDisTheta, AngularDisTheta_sym, "divsym");
	//c->SetTicks(0, 1);
	//rp->Draw();
	//rp->GetUpperPad()->cd();
	
	auto leg = new TLegend();
	leg->SetHeader("Legend","C");
	leg->AddEntry(AngularDisTheta_sym,"Symmetrical beam energy","le");
	leg->AddEntry(AngularDisTheta,"Asymmetrical beam energy","le");
	leg->Draw();
	c->Update();
	gPad->SetTickx();gPad->SetTicky();
	
	TCanvas* c1 = new TCanvas("c1", "Energy distribution");
	EnergyDis_sym->Draw("e1p ");
	EnergyDis->Draw("e1p same");
	//
	//auto rp1 = new TRatioPlot(EnergyDis, EnergyDis_sym, "divsym");
	//c1->SetTicks(0, 1);
	//rp1->Draw();
	//rp1->GetUpperPad()->cd();
	auto leg1 = new TLegend();
	leg1->SetHeader("Legend","C");
	leg1->AddEntry(EnergyDis_sym,"Symmetrical beam energy","le");
	leg1->AddEntry(EnergyDis,"Asymmetrical beam energy","le");
	leg1->Draw();
	c1->SetLogy(1);
	c1->Update();
	gPad->SetTickx();gPad->SetTicky();
	
}
