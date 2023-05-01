/*--------------------------------------------------------------------------------------*/
/*----------------------- PYTHIA script For Tau pair production ------------------------*/
/*--------------------------------------------------------------------------------------*/
// Author: Gajendra Gurung
// Date  : May 1, 2023
//


#include<iostream>
#include"Pythia8/Pythia.h"
#include"TFile.h"
#include"TTree.h"
#include"TThread.h"
using namespace Pythia8;
int const NumberOfThread = 10;
int cBeamEnergy = 91.2;
 
void *handle(void *ptr)
{
	int ith = (long)ptr;
	TFile *output = new TFile(Form("TauProd_Asymmetrical_1e5_t%d.root",ith),"recreate");
	TTree *tree 	= new TTree("tree", "tree");
	
	int id, event, size;
	double m, px, py, pz, Ene, Phi, Theta;
	std::string name;
	
	tree->Branch("id", &id, "id/I");
	tree->Branch("event", &event, "event/I");
	tree->Branch("size", &size, "size/I");
	tree->Branch("m", &m, "m/D");
	tree->Branch("px", &px, "px/D");
	tree->Branch("py", &py, "py/D");
	tree->Branch("pz", &pz, "pz/D");
	tree->Branch("Ene", &Ene, "Ene/D");
	tree->Branch("Phi", &Phi, "Phi/D");
	tree->Branch("Theta", &Theta, "Theta/D");
//	tree->Branch("name", &name, "name/C");

	int nevents = 1e5;
	Pythia8::Pythia pythia;
	
	pythia.readString("Beams:idA = 11");
	pythia.readString("Beams:idB = -11");
	pythia.readString("Beams:eA = 0.90*cBeamEnergy");
	pythia.readString("Beams:eB = 0.10*cBeamEnergy");
	pythia.readString("SoftQCD:all = off");
	pythia.readString("HardQCD:all = on");
	pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
	pythia.readString("PDF:lepton = on");
	pythia.readString("Random:setSeed = on");
	pythia.readString(Form("Random:seed =%d", ith));
	pythia.init();
	
	for(int i =0; i < nevents; i++)
	{
			if(!pythia.next()) continue;
			int entries = pythia.event.size();
			event = i;
			size = entries;
			for(int j =0; j < entries ; j++)
			{
					id  = pythia.event[j].id();
					m   = pythia.event[j].m();
					px  = pythia.event[j].px();
					py  = pythia.event[j].py();
					pz  = pythia.event[j].pz();
					Ene = pythia.event[j].eCalc();
					Phi  = pythia.event[j].phi();
					Theta= pythia.event[j].theta();
//					name = pythia.event[j].name();
					tree->Fill();
			}
	}
	output->Write();
	output->Close();
}
int main()
{
	TThread *th[NumberOfThread];
	for(int i = 0; i < NumberOfThread; i++)
	{
		th[i] = new TThread(Form("th%d",i), handle, (void*)i);
		th[i] ->Run();
	}
	for(int i = 0; i < NumberOfThread; i++)
	{
		th[i]->Join();
	}
    return 0;
}
