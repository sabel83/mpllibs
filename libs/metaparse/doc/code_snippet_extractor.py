#!/usr/bin/python

# Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

import sys

def strip_not_finished_line(s):
  s = s.strip()
  return s[:-1] if s.endswith('\\') else s

def make_copy_paste_friendly(lines):
  result = []
  for l in lines:
    if l.startswith('> '):
      result.append(l[2:])
    elif l.startswith('...> '):
      result[-1] = strip_not_finished_line(result[-1]) + l[5:].lstrip()
  return result

def files_to_write(fn):
  fn_base = fn[:-3] if fn.endswith('.md') else fn
  files = {}

  result = []
  in_cpp_code = False
  counter = 0
  for l in open(sys.argv[1], 'r').readlines():
    if 'copy-paste friendly version' not in l:
      result.append(l)
  
      if in_cpp_code:
        if l.strip() == '```':
          in_cpp_code = False
          if len(code) > 1:
            f = '{0}_{1}'.format(fn_base, counter)
            files['{0}.md'.format(f)] = \
              '```cpp\n{0}\n```\n'.format(''.join(make_copy_paste_friendly(code)))
            result.append(
              '<p align="right">[copy-paste friendly version]({0}.html)</p>\n'
              .format(f)
            )
            counter = counter + 1
  
        elif l.startswith('> ') or l.startswith('...> '):
          code.append(l)
      elif l.strip() == '```cpp':
        in_cpp_code = True
        code = []

  files[fn] = ''.join(result)
  return files

def main():
  if len(sys.argv) != 2:
    print 'Usage: {0} <filename>'.format(sys.argv[0])
    sys.exit(1)

  files = files_to_write(sys.argv[1])
  for fn in files:
    with open(fn, 'w') as f:
      f.write(files[fn])

if __name__ == "__main__":
  main()

