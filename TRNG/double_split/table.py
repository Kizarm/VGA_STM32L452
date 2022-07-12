#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import math
def plot (data, save=False):
  x = []
  y = []
  for i,e in enumerate(data):
    x.append (i)
    y.append (e)
  
  # dekorace
  plt.style.use('seaborn-whitegrid')
  plt.figure(figsize=(10,8))
  plt.xlabel(u'x')
  plt.ylabel(u'y')
  plt.legend()
  plt.title(u'Test')
  
  plt.grid (True)
  plt.plot (x, y, label = 'balik', linewidth = 2.0)
  if save: plt.savefig('img.png')
  else   : plt.show()

def function ():
  result = []
  xr = 800
  xn = 3.0
  dr = math.pi * 2.0 * xn / (float(xr))
  for i in range (0,xr):
    x  = dr * float(i)
    y  = math.cos (x)
    y *= y
    y += 0.05
    y *= math.sin (0.5 * x / xn)
    y  = int (round(float(0xF0) * y))
    result.append(y)
  return ['const unsigned char w_table[]', result]

def exponential ():
  r = []
  p  = 1.0
  for n in range (0, 12):
    z  = math.pow (2.0, float(n))
    q  = math.pow (10000.0, z / 4096.0)
    w  = int (round (q * 1024.0))
    r.append (q)
    p *= q
  print ("p={0:f}".format(p))
  return r

def cplusplus (inst):
  return '#ifdef {1:s}\n{0:s}\n#endif // {1:s}\n'.format(inst, '__cplusplus')

iexpf = '''
const unsigned iexp (const unsigned x) {
  float y = 1.0;
  for (unsigned n=0; n<12; n++) {
    if ((1u << n) & x) {
      y *= exp_table [n];
    }
  }
  return (unsigned) y;
}
'''

def export_c (tables, name):
  #prefix = 'const unsigned short w_table[]'
  header = '__{0:s}_H__'.format(name.upper())
  s  = '#include "{0:s}.h"\n\n'.format(name)
  for table in tables:
    s += '{0:s} = {{'.format(table[0])
    for i,t in enumerate(table[1]):
      if i%16 == 0: s+= '\n'
      s += ' 0x{0:02x},'.format (t)
    s  = s[:-1]
    s += '\n};\n'
  s += 'static const float exp_table [] = {\n'
  et = exponential()
  for e in et: s += '{0:f}f, '.format(e)
  s += '\n};\n'
  s += iexpf
  
  out = open (name + '.c', 'w')
  out.write(s)
  out.close()
  s  = '#ifndef {0:s}\n#define {0:s}\n'.format(header)
  s += cplusplus('extern "C" {')
  for table in tables:
    s += '  extern {0:s};\n'.format(table[0])
  s += '  extern const unsigned iexp (const unsigned x);\n'
  s += cplusplus('};')
  s += '#endif // {0:s}\n'.format(header)
  out = open (name + '.h', 'w')
  out.write(s)
  out.close()

if __name__ == '__main__':
  data = []
  data.append(function ())
  export_c (data, 'table')
  #plot (data[0][1])
