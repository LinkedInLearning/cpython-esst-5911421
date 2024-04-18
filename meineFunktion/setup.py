from setuptools import setup, Extension

setup(
    name='summodule',
    version='1.0',
    ext_modules=[
        Extension('summodule', ['summodule.c']),
    ],
)