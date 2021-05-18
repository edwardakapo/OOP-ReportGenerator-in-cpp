fp: main.o Record.o ReportGenerator.o RegionalBreakdownReport.o PercentageBreakDownReport.o HorsesAndPoniesByRegionReport.o View.o Control.o
	g++ -o fp main.o Record.o ReportGenerator.o RegionalBreakdownReport.o PercentageBreakDownReport.o HorsesAndPoniesByRegionReport.o View.o Control.o

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.h Control.cc ReportGenerator.h RegionalBreakdownReport.h PercentageBreakDownReport.h HorsesAndPoniesByRegionReport.h
	g++ -c Control.cc

View.o: View.h View.cc
	g++ -c View.cc

ReportGenerator.o: ReportGenerator.h ReportGenerator.cc Map.h Record.h
	g++ -c ReportGenerator.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

RegionalBreakdownReport.o: RegionalBreakdownReport.h RegionalBreakdownReport.cc ReportData.h ReportGenerator.h CompareBehaviour.h
	g++ -c RegionalBreakdownReport.cc

PercentageBreakDownReport.o: PercentageBreakDownReport.h PercentageBreakDownReport.cc ReportData.h ReportGenerator.h CompareBehaviour.h
	g++ -c PercentageBreakDownReport.cc

HorsesAndPoniesByRegionReport.o: HorsesAndPoniesByRegionReport.h HorsesAndPoniesByRegionReport.cc ReportData.h ReportGenerator.h CompareBehaviour.h
	g++ -c HorsesAndPoniesByRegionReport.cc
clean:
	rm -f *.o fp
