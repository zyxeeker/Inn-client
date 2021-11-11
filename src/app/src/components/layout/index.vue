<template>
    <n-layout position="static" has-sider>
        <n-layout-sider
            bordered
            collapse-mode="width"
            :collapsed-width="64"
            :native-scrollbar="false"
            style="max-height: 100vh;"
            :collapsed="true"
        >
            <n-menu
                :collapsed-width="64"
                :collapsed-icon-size="22"
                :options="groups"
            />
        </n-layout-sider>

        <n-layout style="height: 100vh;">
            <n-layout-header style="height: 30px;" bordered>
            </n-layout-header>
            <n-layout position="absolute" style="top: 30px;overflow:hidden;" has-sider>
                <n-layout ref="container" content-style="display:flex;flex-direction: column;overflow:hidden;">
                    <!--                    <Group/>-->
                    <router-view name="Room" v-slot="{Component}">
                        <transition enter-active-class="animate__animated animate__bounceInDown"
                                    leave-active-class="animate__animated animate__bounceOutDown" mode="out-in">
                            <!--                        <keep-alive exclude="Home,channel">-->
                            <component :key="$route.params.id" :is="Component"/>
                            <!--                        </keep-alive>-->
                        </transition>
                    </router-view>
                </n-layout>
            </n-layout>
        </n-layout>
    </n-layout>
</template>

<script>
import {h} from 'vue'
import {RouterLink} from 'vue-router'
import {NIcon} from 'naive-ui'
import {Signature} from "@vicons/fa"

function renderIcon(icon) {
    return () => h(NIcon, null, {default: () => h(icon)})
}

export default {
    name: "Layout",
    data() {
        return {
            groups: []
        }
    },
    mounted() {
        window.updateGroup = this.updateGroup
    },
    methods: {
        updateGroup(value) {
            let data = JSON.parse(value);
            for (let i = 0, l = data['data'].length; i < l; ++i) {
                let item = data['data'][i]
                this.groups.push({
                    label: () =>
                        h(
                            RouterLink,
                            {
                                to: {
                                    path: '/group/' + item['name'],
                                    // params: {
                                    //     title: item['params']['title'],
                                    //     des: item['params']['des']
                                    // }
                                }
                            },
                            {default: () => item['name']}
                        ),
                    key: item['name'],
                    icon: renderIcon(Signature)
                })
            }
        }
    }
}
</script>

<style scoped>

</style>
