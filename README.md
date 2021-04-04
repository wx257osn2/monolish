# monolish: MONOlithic LIner equation Solvers for Highly-parallel architecture
monolish is a linear equation solver library that monolithically fuses variable data type, matrix structures, matrix data format, vender specific data transfer APIs, and vender specific numerical algebra libraries.

monolish let developper be oblivious about:
- Performance tuning
- Various processor which execute library  (Intel CPU, NVIDIA GPU, AMD CPU, ARM CPU, A64fx, NEC SX-Aurora TSUBASA etc.) 
- Vender specific data transfer APIs (host RAM to Device RAM)
- Find bottolenecks and perormance benchmark
- Argument data type of matrix / vector operations
- Matrix structure and matrix storage format
- Cumbersome package dependency

---

- Documentation: **URL**
- Source code: https://github.com/ricosjp/monolish/
- Contribution guide : **URL**
- Bug reports: https://github.com/ricosjp/monolish/issues
- Releases: https://github.com/ricosjp/monolish/releases
- Changelog: https://github.com/ricosjp/monolish/blob/master/CHANGELOG.md
- monolish log viewer: https://pypi.org/project/monolish-log-viewer/
- monolish performance viewer: **URL**

---

# Build and Install
## Download binary
XXXXXXX

## Build (for monolish Developpers)
see [doc/installation.md](doc/installation.md)

License
--------
Copyright 2021 [RICOS Co. Ltd.](https://www.ricos.co.jp/)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
