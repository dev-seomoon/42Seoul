#!\bin\bash
git clone https://github.com/gavinfielder/pft.git pft && echo "pft/" >> .gitignore
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
cd ../ && git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
git clone https://github.com/charMstr/printf_lover_v2.git
