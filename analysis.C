void analysis(){
TH1F* AngularDisTheta_sym; TH1F* AngularDisPhi_sym; TH1F* EnergyDis_sym;
TFile* g = new TFile("Symm_Distribution.root");
AngularDisTheta_sym = (TH1F*)g -> Get("AngularDisTheta"); AngularDisTheta_sym ->SetLineColor(9);
AngularDisPhi_sym = (TH1F*)g -> Get("AngularDisPhi");
	EnergyDis_sym = (TH1F*)g -> Get("EnergyDis"); EnergyDis_sym ->SetLineColor(9);
	
TH1F* AngularDisTheta; TH1F* AngularDisPhi;  TH1F* EnergyDis;
TFile* h = new TFile("Asymm_Distribution.root");
AngularDisTheta = (TH1F*)h -> Get("AngularDisTheta");
AngularDisPhi = (TH1F*)h -> Get("AngularDisPhi");
EnergyDis = (TH1F*)h -> Get("EnergyDis");

gStyle->SetOptStat(0);

TCanvas* c = new TCanvas("c", "Ratio of Angular Distribution");
auto rp = new TRatioPlot(AngularDisTheta_sym, AngularDisTheta, "divsym");
c->SetTicks(0, 1);
rp->Draw();
rp->GetUpperPad()->cd();

auto leg = new TLegend();
leg->SetHeader("Legend","C");
leg->AddEntry(AngularDisTheta_sym,"Sym","le");
leg->AddEntry(AngularDisTheta,"Asym","le");
leg->Draw();
c->Update();

TCanvas* c1 = new TCanvas("c1", "Ratio of Energy distribution");
auto rp1 = new TRatioPlot(EnergyDis_sym, EnergyDis, "divsym");
c1->SetTicks(0, 1);
rp1->Draw();
rp1->GetUpperPad()->cd();
auto leg1 = new TLegend();
leg1->SetHeader("Legend","C");
leg1->AddEntry(EnergyDis_sym,"Sym","le");
leg1->AddEntry(EnergyDis,"Asym","le");
leg1->Draw();
c1->Update();

}
