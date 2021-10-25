<template>
    <n-page-header subtitle="TEST-ID-20211025" @back="handleBack">
        <template #title>
            <a href="" style="text-decoration: none; color: inherit;">TEST</a>
        </template>
        <template #header>
            <n-breadcrumb>
                <n-breadcrumb-item>TEST</n-breadcrumb-item>
                <n-breadcrumb-item>TEST</n-breadcrumb-item>
                <n-breadcrumb-item>TEST</n-breadcrumb-item>
                <n-breadcrumb-item>TEST</n-breadcrumb-item>
            </n-breadcrumb>
        </template>
        <template #avatar>
            <n-avatar src="https://cdnimg103.lizhi.fm/user/2017/02/04/2583325032200238082_160x160.jpg"/>
        </template>
        <template #extra>
            <n-space>
                <n-button>TEST</n-button>
                <n-dropdown :options="options" placement="bottom-start">
                    <n-button :bordered="false" style="padding: 0 4px">···</n-button>
                </n-dropdown>
            </n-space>
        </template>
    </n-page-header>
</template>

<script>
import {defineComponent} from 'vue'
import {useMessage} from 'naive-ui'

export default defineComponent({
    name: "MainHeader",
    setup() {
        const message = useMessage()
        return {
            handleBack() {
                message.info('[onBack]')
            },
            options: [
                {
                    label: 'TEST',
                    key: '1'
                },
                {
                    label: 'TEST',
                    key: '2'
                },
                {
                    label: 'TEST',
                    key: '3'
                }
            ]
        }
    }
})
</script>

<style>
.header {
    text-align: left;
}
</style>
