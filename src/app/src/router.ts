// Vue Router 4
import {createRouter, createWebHistory} from "vue-router";
// @ts-ignore
import {Main} from "./components/layout/components/Main/index.ts";

export default createRouter({
    history: createWebHistory(),
    routes: [{
        path: '/m',
        name: 'toContentHeader',
        components: {Main: Main},
        props: {Main: true}
    }
    ]
});