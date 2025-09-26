from setuptools import find_packages
from setuptools import setup

setup(
    name='cooperative_localization',
    version='1.0.0',
    packages=find_packages(
        include=('cooperative_localization', 'cooperative_localization.*')),
)
