#include "Fingerprint.hpp"
using namespace OpenLab::io;

#define OUTPUT

#define FINGERPRINT_DATA_FILENAME "fingerprint/fp.xml" // �t�@�C����
fp::FingerprintIOFactory::Filetype iotype = fp::FingerprintIOFactory::XML; // XML�œ��o��

int main()
{	
#ifdef OUTPUT

	fp::AbstractFingerprintIO *io = fp::FingerprintIOFactory::createFingerprintIO(fp::FingerprintIOFactory::FILE);
	std::list<fp::Fingerprint> fingerprints = io->createFingerprintList("fingerprint/csv/fp.csv");
	delete io;
	
	io = fp::FingerprintIOFactory::createFingerprintIO(fp::FingerprintIOFactory::XML);
	io->writeFingerprintList("fingerprint/xml/fp.xml", fingerprints);
	delete io;
	
#else
	fp::AbstractFingerprintIO *io = fp::FingerprintIOFactory::createFingerprintIO(fp::FingerprintIOFactory::XML);
	std::list<fp::Fingerprint> fingerprints = io->createFingerprintList("fingerprint/xml/fp.xml");
	delete io;

    // �ǂݍ��񂾓��e��W���o�͂ɕ\��
    boost::archive::text_oarchive oarchive(std::cout);
	oarchive << (fingerprints);

#endif

	return 0;
}
