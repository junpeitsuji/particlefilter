#pragma once

#include "Fingerprint.hpp"
#include <iostream>
#include <boost/tokenizer.hpp>

namespace OpenLab {

	namespace io {

		namespace fp {

			class RawfileFingerprintIO : public AbstractFingerprintIO
			{
			public:
				virtual std::list<Fingerprint> createFingerprintList(const char *filename) {
					char *env         = getenv("DATA_SOURCE_PATH");
					char filepath[200];
					sprintf(filepath, "%s/%s", env, filename);

					std::list<Fingerprint> fingerprints;

					// FileÇÃì«Ç›çûÇ›
					std::ifstream ifs(filepath);
					std::string str;


					while(ifs && getline(ifs, str)) {

						typedef boost::char_separator<char> char_separator;
						typedef boost::tokenizer<char_separator> tokenizer;

						char_separator sep(",", "", boost::keep_empty_tokens);
						tokenizer tokens(str, sep);

						int id;
						double x;
						double y;
						double z;
						int rid;
						int num;
						double val;
						double dev;

						Fingerprint fin;

						int i = 0;
						for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter) {

							switch(i){
							case 0:
								id =  atoi((*tok_iter).c_str());
								std::cout << "id:" << id << std::endl;
								break;
							case 1:
								x  =  atof((*tok_iter).c_str());
								std::cout << "x:" << x << std::endl;
								break;
							case 2:
								y  =  atof((*tok_iter).c_str());
								std::cout << "y:" << y << std::endl;
								break;
							case 3:
								z  =  atof((*tok_iter).c_str());
								std::cout << "z:" << z << std::endl;
								break;
							case 4:
								rid = atoi((*tok_iter).c_str());
								std::cout << "rid:" << rid << std::endl;
								break;
							case 5:
								num = atoi((*tok_iter).c_str());
								std::cout << "num:" << num << std::endl;
								break;
							case 6:
								val = atof((*tok_iter).c_str());
								std::cout << "val:" << val << std::endl;
								break;
							case 7:
								dev = atof((*tok_iter).c_str());
								std::cout << "dev:" << dev << std::endl;
								break;
							default:
								break;

							}
							i++;

						}
						fin.id = id;
						fin.location.x = x;
						fin.location.y = y;
						fin.location.z = z;
						fin.values.insert    ( std::map<int, double>::value_type( rid, val ) );
						fin.deviations.insert( std::map<int, double>::value_type( rid, dev ) );
						fin.nums.insert      ( std::map<int, int>::value_type   ( rid, num ) );
						fingerprints.push_back(fin);
						std::cout << std::endl;
					}

					return fingerprints;
				}

				virtual void writeFingerprintList(const char *filename, std::list<Fingerprint> fingerprintList){
				}
			};

		};

	};

};
