# microbitv2.2-TTK4235-environment
VSCode environment for debugging software developed for micro:bit v2.2.1 for Embedded Systems Course TTK4235

## Install

> Lab PC Installation

```
wget https://raw.githubusercontent.com/tordnat/microbitv2.2-TTK4235-environment/main/lab_installer.sh && chmod +x installer.sh && sudo ./installer.sh && pip3 install --user testresources==2.0.1 pyocd==0.34.3
```
> Normal Installation

```
wget https://raw.githubusercontent.com/tordnat/microbitv2.2-TTK4235-environment/main/installer.sh
```

```
chmod +x installer.sh
```
```
sudo ./installer.sh
```
Install Python dependencies

```
pip3 install --user testresources==2.0.1 pyocd==0.34.3
```

```
git clone https://github.com/tordnat/microbitv2.2-TTK4235-environment.git
```

## Common issues

To fix broken library linking

> No such file libncursesw.so.5

```

    ln /usr/lib/x86_64-linux-gnu/libncursesw.so.6 /usr/lib/x86_64-linux-gnu/libncursesw.so.5
```