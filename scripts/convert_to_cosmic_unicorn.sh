#!/bin/sh

input_file=$1
output_class=$2

(
  cat <<END
#ifndef UNICORN_FUN_${output_class}_HPP
#define UNICORN_FUN_${output_class}_HPP

#include <cstdint>

class ${output_class} {
public:
    constexpr static uint8_t image[] = {
END
  convert -resize 32x32 ${input_file} rgb:- | xxd -i
  cat <<END
    };

};


#endif //UNICORN_FUN_${3}_HPP
END
) >>${output_class}.hpp