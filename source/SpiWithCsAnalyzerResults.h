#ifndef SPIWITHCS_ANALYZER_RESULTS
#define SPIWITHCS_ANALYZER_RESULTS

#include <AnalyzerResults.h>

#define SPI_ERROR_FLAG ( 1 << 0 )

class SpiWithCsAnalyzer;
class SpiWithCsAnalyzerSettings;

class SpiWithCsAnalyzerResults : public AnalyzerResults
{
public:
	SpiWithCsAnalyzerResults( SpiWithCsAnalyzer* analyzer, SpiWithCsAnalyzerSettings* settings );
	virtual ~SpiWithCsAnalyzerResults();

	virtual void GenerateBubbleText( U64 frame_index, Channel& channel, DisplayBase display_base );
	virtual void GenerateExportFile( const char* file, DisplayBase display_base, U32 export_type_user_id );

	virtual void GenerateFrameTabularText(U64 frame_index, DisplayBase display_base );
	virtual void GeneratePacketTabularText( U64 packet_id, DisplayBase display_base );
	virtual void GenerateTransactionTabularText( U64 transaction_id, DisplayBase display_base );

protected: //functions

protected:  //vars
	SpiWithCsAnalyzerSettings* mSettings;
	SpiWithCsAnalyzer* mAnalyzer;
};

#endif //SPIWITHCS_ANALYZER_RESULTS
