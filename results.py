# -*- coding: utf-8 -*-

import dash
from dash.dependencies import Input, Output
import dash_auth
import dash_enterprise_auth as auth
import dash_core_components as dcc
import dash_html_components as html
import pandas as pd
import numpy as np

external_stylesheets = ['https://codepen.io/chriddyp/pen/bWLwgP.css']
app = dash.Dash(__name__, external_stylesheets=external_stylesheets)

VALID_USERNAME_PASSWORD_PAIRS = {
    'admin': 'admin'
}

auth = dash_auth.BasicAuth(
    app,
    VALID_USERNAME_PASSWORD_PAIRS
)

adress = 'C:\\Users\\Vadim\\Desktop\\res.csv'
data = np.loadtxt(adress, delimiter=',', skiprows=1)
# file = pd.read_csv(adress, sep=',')
light = data
n = data.shape[0]
# print(n)
times = np.linspace(1, n, n)
# print(times)
lightval = light[n-1]
out = ''

if((lightval >= 700)): out = "Light scale: shine"

if(((lightval < 700) & (lightval >= 600))): out = "Light scale: bright"

if(((lightval < 600) & (lightval >= 500))): out = "Light scale: dim"

if((lightval < 500)): out = "Light scale: dark"

app.layout = html.Div(children=[

    html.Div([
        html.H1('Light level information'),
        html.Div([
            html.P(out),
            html.P('Now your light level is ' + str(light[n-1])),
            ])
    ]),

    dcc.Graph(
        id='light',
        figure={
            'data': [
                {'x': times, 'y': light},
            ],
            'layout': {
                'title': 'Light'
            }
        }
    )
])

if __name__ == '__main__':
    app.run_server(debug=True)
